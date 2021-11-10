# TreeWalker

TreeWalker consists of a versatile and adaptible tree search library with the ability to simply change the exploration strategy (and hence the search algorithm) by changing a single function in the code, i.e. the comparator.
The program also provides several statistics and metrics about the chosen search algorithm, and also automatically plots graphs to visually represent these statistics, facilitating potential further analysis.  

Search algorithms implemented:  
- Breadth-First Search (code: bfs)
- Depth-First Search (code: dfs)
- Greedy Search (code: greedy)
- Greedy Search favoring the larger value (code: greedymax)  

Additional Features:  
- ASCII tree printing (for small trees, i.e. those with low branching factor and low depth).
- Ability to set the search algorithm using a command line option.
- Ability to add and define custom search methods.
- Ability to toggle whether analysis statistics and plotted graphs are shown.
- Automatic graph plotting (if analysis is enabled).
- Optional ability to pass input files with different names (apart from the default input file) using a command line option.

&nbsp;  
## Compilation, Execution and Output:     
- `make run [ana] searchmethod [D=datafilename]`
	- Parameters enclosed in `[]` are optional  
	- `[ana]` : if written, the analysis table is printed and the analysis graphs are plotted. Otherwise, only the search output is shown.  
	- `searchmethod` options : `bfs | dfs | greedy | greedymax`  
	- `[D=datafilename]` : File path not to be included, it is presumed all the data files are in the `testcases` directory. If this option is not specified, the default input file is data1.txt  
&nbsp;
- Execution Examples  
	- `make run bfs` : Uses `data1.txt`, does not print analysis or plot graphs.  
	- `make run ana dfs` : Uses `data1.txt` again, but this time, analysis and graphs are generated and shown.  
	- `make run ana greedy D=data4.txt` : Uses `data4.txt`, analysis and graphs are generated and shown.  
&nbsp;
- More search methods can be arbitrarily added without modifying the makefile at all by:  
	- Adding the name of the search to the `valid_searches` array, and then  
	- Adding the condition corresponding to it in the comparator method.  
&nbsp;
- Input File Format  
	`<number_of_nodes 'n'>`  
    `<state_number> <value> <parent_state_number>`  
    `...`  
    `n times`  
&nbsp;
- Output format  
	- ASCII tree printed (tree not printed for n>=20)  
	- Search traversal result printed (not printed in case the search name is invlaid)  
	- Analysis table printed and plotted graphs shown (only if ana flag is enabled) \
&nbsp;  
## Contributors 
- Aakash Reddy 
- Dhruv Mittal
- Pranav Manu
- Pratyay Suvarnapathaki
- Rohan Gupta  


