International Institute of Information Technology, Hyderabad  
Data Structures and Algorithms Term Project
# Team 3 - Tree Search Library
## Team Members:  
#### Subteam 'Tree+Algo'  
- Dhruv Mittal, 2020113017 : Implementation of functions to push nodes from AdjList to PQ and to free the memory from the AdjList.
- Aakash Reddy, 2020102034 : Debugging and testing of adjacency list functions.
- Rohan Gupta, 2020112022 : Implementation of functions to push nodes into AdjList, to print the AdjList and to create a node.
#### Subteam 'PQ'  
- Pranav Manu, 2020112019 : Implementation of pq functions.
- Pratyay Suvarnapathaki, 2020111016 : Debugging and interface abstraction in pq implementation ; Planning and debugging the unified search algorithm.  
&nbsp;  
## Implemented Till Now:  
- Breadth-First Search
- Depth-First Search
- Greedy search (favoring lesser/greater value) 
## To-Do:  
- Accepting search mode via command line flags  
- Analytics
- Optionally, A-star and MCTS algorithms  
&nbsp;  
## Compilation and Execution:  
* Put data into data.txt  
*	 `make run [searchmethod]`   
	Here, `[searchmethod]` can be:  
 	- bfs    
 	- dfs  
 	- greedy  
 	- greedymax   
More search methods can be arbitrarily added in the comparator method without modifying the makefile at all.