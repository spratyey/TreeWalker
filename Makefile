run: main.c node.h node.c PriorityQueue.h PriorityQueue.c AdjList.h AdjList.c 
	@ gcc main.c node.c PriorityQueue.c AdjList.c -g -fsanitize=address -fsanitize=undefined
	@ ./a.out $(filter-out $@,$(MAKECMDGOALS)) < data.txt
%:
	@:
