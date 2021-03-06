B. Pasha and Phone 
大意就是给长度为n的数，分为n/k部分，即每部分k个digit，所以总共有n/k个k位数。对于第i个数，求能被Ai整除，且不以Bi开头的数的个数。求这个n位数可能的情况。 
可以看到总的情况ans = ans1 * ans2 * … ans(n/k)。 
分别求每一小部分的可能情况即可， 即求k位数能背中能被A整除又不以B开头的数，其中能被A整除的个数为tot = (10^k - 1)/A + 1，整数除法。以B开头的能被A整除的最小数为 num1 = (B * 10^(k - 1) / A)向上取整 * A，以B开头的能背A整除的最大数为 num2 = ((B+1) * 10^(k - 1) - 1) / A * A，整数除法。如果num1 <= num2,则tot减去（num2 - num1) / A + 1

C. Warrior and Archer 
题目意思是有N个数，A和B每次选一个去除，直到剩2个，A和B都做出最优选择的话最后结果是一定的，问最后两个数之间的距离。 
这题比赛的时候是N为任意，但是因为N奇数的时候好像答案有问题，现在重新post出来的时候已经定义N为偶数了，那这样就简单了。 
先sort arr，然后设P=min{arr[i + n / 2] - arr[i]}。我们设最后的结果为ans，然后证明P即为ans。因为首先很显然P是小于等于ans的，假设arr[I + n / 2] - arr[I] == P，则对于warrior来说，他只要保证将j < I 以及 j > I + n / 2的值全部删去就可以，如果Archer中间捣乱删除了warrior本来应该删除的，那么warrior就删除掉arr[I]或者arr[I + n / 2],这样结果就比P小了。 
ans也肯定是大于等于P的，我们将n-2次选择看成(n - 2) / 2次回合，每一回合warrior先选，对于Archer来讲，无论warrior先选什么，假设其选J，archer只要选对应的J + n / 2或者 J - n / 2即可，最后剩余的一对一定大于等于P。 
综上，ans=P = min{arr[i + n / 2] - arr[i]} 

D. Max and Bike 
题意大概就是自行车轮子上有标记，车位置任意（起点之前），从标记与起点重合开始计时，到标记与终点重合结束，求这段时间的最小值。 
假设从开始到结束标记转了T圈，T为浮点数，T的整数部分时间肯定是确定的，2*PI*R/V*int(T)。现在考虑小数部分t，t可以转化为a, a代表转得角度，在这段时间内走得距离D=(f-s-int(T)*2*PI*R)是一定的，如何使t尽量小？这样就只能走圆的上方最快，因为速度是一定的，额外的速度来自于标记跟随圆运动时的水平速度，圆上方时这个分量是最大的，所以画图可以知道sin(a/2)*2+t*2*PI*R等于D，二分确定t的最小值即可