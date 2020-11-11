range_new_files = (20, 25)
arg_prefix = "args_"
res_prefix = "res_"
stderr_prefix = "stderr_"
file_extension = ".txt"
root = "test/"
with open(f"{root}{arg_prefix}1{file_extension}", "r") as arg_o, \
    open(f"{root}{res_prefix}1{file_extension}", "r") as res_o, \
    open(f"{root}{stderr_prefix}1{file_extension}", "r") as stderr_o:
    arg_o_str = arg_o.read()
    res_o_str = res_o.read()
    stderr_o_str = stderr_o.read()
    for i in range(*range_new_files):
        with open(f"{root}{arg_prefix}{i}{file_extension}", "w") as arg_d, \
             open(f"{root}{res_prefix}{i}{file_extension}", "w") as res_d, \
             open(f"{root}{stderr_prefix}{i}{file_extension}", "w") as err_d:
            arg_d.write(arg_o_str)
            res_d.write(res_o_str)
            err_d.write(stderr_o_str)
