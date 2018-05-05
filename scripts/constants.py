import datetime

instances_dir  = '../instances'
solutions_dir  = '../solutions'
stat_files_dir = '../stat_files'
exec_command = '../CPFSolver/bin/CPFSolver'

sury_exec_command = '../../reLOC-0.16-takao_013/src/insolver_reLOC'
sury_instances_dir = '../instances'
sury_solutions_dir  = '../sury_solutions'

date = datetime.datetime.now().strftime("%m%d%H%M") 

print(date)

executed_commands_file = 'executed_' + date + '.txt'
timed_out_commands_file = 'timed_out_' + date + '.txt'
segfault_commands_file = 'segfault_' + date + '.txt'

table_filename = 'table_' + date + '.csv'
