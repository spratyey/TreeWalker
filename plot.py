import matplotlib.pyplot as plt
from matplotlib.ticker import FormatStrFormatter
import numpy as np
import math
import csv
plt.style.use("horizon.mplstyle")
x = []
y1 = []  
y2 = []
y3 = []
y4 = []  
with open('plot.csv','r') as csvfile:
	plots = csv.reader(csvfile, delimiter=',')
	for row in plots:
		x.append(float(row[0]))
		y1.append(float(row[1]))
		y2.append(float(row[2]))
		y3.append(float(row[3]))
		y4.append(float(row[4])) 
		#no problem here, python's float corresponds to C's double

xmax = x[-1]

# Initialise the subplot function using number of rows and columns
figure, axis = plt.subplots(2, 2)

if xmax<=20:
	axis[0, 0].locator_params(axis="x", nbins=xmax)
	axis[0, 1].locator_params(axis="x", nbins=xmax)
	axis[1, 0].locator_params(axis="x", nbins=xmax)
	axis[1, 1].locator_params(axis="x", nbins=xmax)

axis[0, 0].plot(x, y1)
axis[0, 0].set_title("Max Depth")
axis[0, 0].yaxis.set_major_formatter(FormatStrFormatter('%.3f'))  


axis[0, 1].plot(x, y2)
axis[0, 1].set_title("Average Depth")
axis[0, 1].yaxis.set_major_formatter(FormatStrFormatter('%.3f'))  


axis[1, 0].plot(x, y3)
axis[1, 0].set_title("Max Children")
axis[1, 0].yaxis.set_major_formatter(FormatStrFormatter('%.3f'))  



axis[1, 1].plot(x, y4)
axis[1, 1].set_title("Branching Factor")
axis[1, 1].yaxis.set_major_formatter(FormatStrFormatter('%.3f'))  


plt.show()