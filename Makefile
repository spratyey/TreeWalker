D = data1.txt
DPATH=./testcases/
run: main.c node.h node.c PriorityQueue.h PriorityQueue.c TSL.h TSL.c TreeRep.c TreeRep.h
	@ gcc main.c node.c PriorityQueue.c TSL.c TreeRep.c -g -fsanitize=address -fsanitize=undefined
	@ ./a.out $(filter-out $@,$(MAKECMDGOALS)) < $(DPATH)$(D)
ana : plot.csv plot.py horizon.mplstyle
	@ python3 plot.py
%:
	@: