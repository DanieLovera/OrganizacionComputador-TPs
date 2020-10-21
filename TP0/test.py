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

def main(command, input_prefix, result_prefix):
    input_files = glob.glob(f'{input_prefix}*')
    
    test_files = { file_name[len(input_prefix):]: 
                    [file_name,] 
                       for file_name in input_files }

    for id, files in test_files.items():
        files.append(f'{result_prefix}{id}')
    
    for file, output_file in test_files.values():
        result_obtained = run_command(f'{command} < {file}')[1]
        with tempfile.NamedTemporaryFile() as tmp:
            tmp.write(bytes(result_obtained, encoding='utf-8'))
            tmp.read() # TODO: No sé por qué hay que leer para que funcione
            code_diff, stdout_diff, _ = run_command(f"""
                diff {output_file} {tmp.name}
            """)
            if code_diff == 0:
                print('.', end='')
                continue 
            print()
            print(f'Ejecución con {file} comparación con {output_file}')
            print(stdout_diff)
    print()


if __name__ == "__main__":
    if len(sys.argv) == 4:
        command, input_prefix, result_prefix = sys.argv[1:]
        main(command, input_prefix, result_prefix)
    else:
        print("""
        Use: python test.py command input_prefix result_prefix
        command: comando a ejecutar.
        input_prefix: prefijo de los archivos que se usaran como entrada.
        result_prefix: prefijo de los archivos a comparar.
        """)
