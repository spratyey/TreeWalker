run: main.c node.h node.c PriorityQueue.h PriorityQueue.c AdjList.h AdjList.c TreeRep.c TreeRep.h
	@ gcc main.c node.c PriorityQueue.c AdjList.c TreeRep.c -g -fsanitize=address -fsanitize=undefined
	@ ./a.out $(filter-out $@,$(MAKECMDGOALS)) < data.txt
%:
	@:
