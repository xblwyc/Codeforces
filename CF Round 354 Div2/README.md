A - Nicholas and Permutation

O(n^3)暴力搜即可。。。

B - Pyramid of Glasses

和GCJ有一年题很像，DP解即可，dp[i][j]表示第i层第j个接的酒量，如果i，j大于1，则多余部分均分传递给dp[i + 1][j]和dp[i + 1][j + 1]， 最后查一遍哪些酒杯>=1即可。

C - Vasya and String

二元数组，左右两侧各加一个守护变量，维持一个k + 2大小的窗口，用窗口内的数-2更新结果即可。

D - Theseus and labyrinth

纯模拟题，BFS搜即可，用dp[i][j][k]记录一下是否曾经访问过，i,j表示坐标， 0 <= k <= 3表示rotate了多少次。

E - Trains and Statistic
从后往前，这个是key。。
待完成。。