What is K-Means?

K-Means is a popular unsupervised machine learning algorithm used to group similar data points into clusters. It does not require labeled data and works by identifying natural groupings within the input dataset.

What does it do?

Given a dataset and a number k
K-Means organizes the data into k clusters such that points within the same cluster are as similar as possible, while points in different clusters are as dissimilar as possible. It is commonly used in customer segmentation, image compression, pattern recognition, and exploratory data analysis.

How does it work?

1. Choose the number of clusters k
2. Initialize k centroids (typically at random positions).
3. Assign each data point to the nearest centroid, forming k clusters.
4. Recalculate each centroid as the average (mean) of all points in its cluster.
5. Repeat steps 3 and 4 until the centroids stop moving significantly or a maximum number of iterations is reached.

The result is a set of clusters where each data point belongs to the cluster with the closest centroid.