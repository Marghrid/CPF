from os import system

for size in (4, 8, 16, 32):
	makespan_limit = size * size *2
	for robots_prob in (0.2, 0.3, 0.4):
		for obst_prob in (0.1, 0.2, 0.3, 0.4):
			n_robots = int(size * size * robots_prob);
			for seed in (5, 31, 327, 616, 895):

				filename  = "grid_" + str(size) + "x" + str(size)
				filename += "_a" + str(n_robots)
				filename += "_o" + str(obst_prob)
				filename += "_s" + str(seed)

				aux  = " -i ../M_instances/"  + filename + ".cpf"
				aux += " -o ../M_instances/" + filename + ".out"
				aux += " -s ../M_stats_files/" + filename + ".txt"
				aux += " -e simplified"
				aux += " -search binary"
				aux += " -v 0"

				output = ""
				print ("../CPFSolver/bin/CPFSolver" + aux)
				system("../CPFSolver/bin/CPFSolver" + aux)

for dim in (3, 9):
	makespan_limit = 2**dim * 2
	for robots_prob in (0.1, 0.2, 0.4):
		aux = 2**dim * robots_prob
		n_robots = int(aux);
		for seed in (5, 31, 327, 616, 895):
			filename = "hyper_dim" + str(dim) + "_a" + str(n_robots) + "_" + str(seed)
			
			aux  = " -i ../M_instances/"  + filename + ".cpf"
			aux += " -o ../M_instances/" + filename + ".out"
			aux += " -s ../M_stats_files/" + filename + ".txt"
			aux += " -e simplified"
			aux += " -search binary"
			aux += " -v 0"

			print ("../CPFSolver/bin/CPFSolver" + aux)
			system("../CPFSolver/bin/CPFSolver" + aux)