int MaxDepth(ptr node, int prev)
{
    int temp_max = prev;

    if (prev < node->depth)
        temp_max = node->depth;

    return temp_max;
}

double AvgDepth(ptr node)
{
    weighted_depth += node->depth;
    double average = weighted_depth / count;
    return average;
}

void printAnalysis(int maxnode)
{
    for(int i = 0; i < maxnode; i++)
        printf("%d, %d, %lf, %lf", i, max[i], avg[i], bf[i]);
}