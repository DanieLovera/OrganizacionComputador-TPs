import subprocess
import sys
import glob
import tempfile

def run_command(command):
    proc = subprocess.Popen(command, 
                            stdout=subprocess.PIPE, 
                            stderr= subprocess.PIPE, 
                            shell=True,
                            universal_newlines=True)
    
    std_out, std_err = proc.communicate()
    return proc.returncode, std_out, std_err

def main(command, input_prefix, result_prefix, stderr_prefix):
    input_files = glob.glob(f'{input_prefix}*')
    
    test_files = { file_name[len(input_prefix):]: 
                    [file_name,] 
                       for file_name in input_files }

    for id, files in test_files.items():
        files.append((f'{result_prefix}{id}',
                      f'{stderr_prefix}{id}'))
    
    for file, (output_file, stderr_file) in test_files.values():
        result_obtained_stdout, result_obtained_stderr = \
                                    run_command(f'{command} `cat {file}`')[1:]
        with tempfile.NamedTemporaryFile() as tmp_stdout, \
            tempfile.NamedTemporaryFile() as tmp_stderr:
            tmp_stdout.write(bytes(result_obtained_stdout, encoding='utf-8'))
            tmp_stdout.read()
            
            tmp_stderr.write(bytes(result_obtained_stderr, encoding='utf-8'))
            tmp_stderr.read()
            
            code_diff, stdout_diff, _ = run_command(f"""
                diff {output_file} {tmp_stdout.name}
            """)

            stderr_code_diff, stderr_stdout_diff, _ = run_command(f"""
                diff {stderr_file} {tmp_stderr.name}
            """)

            if code_diff == 0 and stderr_code_diff == 0:
                print('.', end='')
                continue 
            print()
            print(f'Ejecución con {file} comparación con {output_file}')
            print(stdout_diff)
            print('Diferencia en stderr')
            print(stderr_stdout_diff)
    print()


if __name__ == "__main__":
    if len(sys.argv) == 5:
        command, input_prefix, result_prefix, stderr_prefix = sys.argv[1:]
        main(command, input_prefix, result_prefix, stderr_prefix)
    else:
        print("""
        Use: python test.py command input_prefix result_prefix stderr_prefix
        command: comando a ejecutar.
        input_prefix: prefijo de los archivos que se usaran como entrada.
        result_prefix: prefijo de los archivos a comparar.
        """)
