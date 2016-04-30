A - Reberland Linguistics
大意就是有一个字符串s，想把他分成root+若干个appendstring的形式，appendstring长度为2或者3，appendstring相邻两个不能相同，让记录一下可能的分割中所有的appendstring。

一开始看错题了以为appendstring里不能有相同的，结果想了一个小时也没想出来。。后来发现是相邻2个不能相同。
用一个set去记录结果就可以，因为总共有26*26*26 + 26*26 大约等于10000多种情况。
从末尾考虑，每次分出来2个或者3个字符，如果分出来的字符满足不等于前一个，那么他一定是可以被push到set里的（分割出来以后剩余的作为root即可），然后我们继续对剩余的字符串进行同样的操作。
可以看出来这种递归算法有很多重复计算，之前在某个index，前面一次分割分出来2个或者3个以后，如果这次又到了这个index，且前一次分割为2个或者3个，那么可以直接结束这次递归。
所以用一个数组记忆一下之前访问的情况即可，每个index分为长度2和长度3。还有一个问题就是我用递归写会爆栈，所以改用了queue实现。

B - World Tour
大意就是给定一个有向图，n<3000,m < 5000，求4个点a,b,c,d，使得a->b的最短距离+b->c的最短距离+c->d的最短距离最大。

首先用SPFA算出任意两点的最短距离，记录在d[i][j]中。
考虑如何选取这4个点，n^4次方肯定是超时的，最多是n^2,考虑枚举中间的两个点，然后求对应的a，我们可以之前preprocess一下记录一下到每个点的距离最长的最短距离的长度和编号，这样可以在O(1)时间内求出到b长度最长的点a，对于d用类似的方法。需要注意的是因为可能存在a=c，a=d的情况，所以我们要存最大的前3个，这样在这3个之中肯定存在一种合法的情况。