#include <iostream>

using namespace std;
/*
Dynamic Programming (DP):
	When we solve a recursive problem that its sub-problems overlaps, hence calling sub-problems
	More than once and repeating its calculation in nature that typically makes the order exponentials!
	When the original space is small enough to be memorized, then saving these sub-problems
		makes order small too, as sub-problems calculated once.
*/

#define MAX 100

//Memorization
int savedAnswers[MAX];		// Initialized to -1, means no answer
int fibSave(int n)
{
	if(n <= 1)
		return 1;

	if(savedAnswers[n] != -1)
		return savedAnswers[n];

	return savedAnswers[n] = fibSave(n-2) + fibSave(n-1);
}

// General Rules:

// 1- Recursive Function
// 2- Sub-calls Overlap
// 3- Small Search Space, so putting in memory is doable

// Do we need to apply DP for merge sort? NEVER, a call will never be repeated! like most of D & C problems.

// Dynamic Programming most typical cases: Minimization, Maximization and Counting. But could have adhock usages.

// In fact, above code is not called DP, it is call Memoization (NOT Memorization).
	// It is a technique when we have a recurive function and save calls)


// DP is to build bottom up according to recurrence while Memoization is top-down


//dp:build from bottom to top

int dp_fib(int n)
{
	int fib[MAX];
	fib[0] = fib[1] = 1;	// base case

	for(int i = 2; i <= n; ++i)
		fib[i] = fib[i-1] + fib[i-2];	// bottom up according to recurrence

	return fib[n];
}


// Writing Memoization is much more natural, although there are cases when DP is a must




// Let's move to some other examples! Remember:

// Given grid of positive numbers, Start from 0, 0 and end at n, n. Move only to right and down - find path with sum of numbers is maximum.

/*
15
24
512
678
149
What paths there" 51289, 51789, 51749, 56789, 56749, 56149 ..
				  It is like: 5 { 1 {289, 789, 749}, 6{789, 749, 149} }
				  In other words, 5 needs answer of 1 and of 6 to maximize over them.
*/
int n;
int grid[MAX][MAX];
bool valid(int r, int c)
{
    return r>0&&r<=n&&c>0&&c<=n;
}
// Think in function F(i, j) that find solution from (i, j) to (n, n)

int maxPathSum(int r, int c)
{
	if( !valid(r, c))
		return 0;

	if (r == n-1 && c == n-1)
		return grid[r][c];	// base

	int path1 = maxPathSum(r, c+1);	// right
	int path2 = maxPathSum(r+1, c);	// down

	return grid[r][c] + max(path1, path2);
}




// How to trun code to memization?
// 1- Create array of input dimensions, and output of its return.
// E.g. int mem[MAX][MAX];
// Initialize it with a value that will never be a correct answer, e.g. -1
// If value is -1, then it is not visited before. Else, use saved value

int mem[MAX][MAX];	// R & C is in range N. Function return int
int maxPathSum_save(int r, int c)
{
	//1- Always hanle invalid calls first
	if( !valid(r, c))
		return 0;

	//2- Handle Base cases
	if (r == n-1 && c == n-1)
		return grid[r][c];	// base

	//3- check if visited before

	if(mem[r][c] != -1)
		return mem[r][c];

	int path1 = maxPathSum_save(r, c+1);	// right
	int path2 = maxPathSum_save(r+1, c);	// down

	return mem[r][c] = grid[r][c] + max(path1, path2);
}




// Dp need good recursive mentality, that views answer in term of recursion! So develop your skills!

// Many DPs follow a certain pattern (style), we will investigate some of them




/*
 Consider an arbitrary sequence of integers. One can place + or - operators between integers in the sequence,
 	 thus deriving different arithmetical expressions that evaluate to different values. Let us, for example,
 	 take the sequence: 17, 5, -21, 15. There are eight possible expressions:
17	+	5	+	-21	+	15	=	16
17	+	5	+	-21	-	15	=	-14
17	+	5	-	-21	+	15	=	58
17	+	5	-	-21	-	15	=	28
17	-	5	+	-21	+	15	=	6
17	-	5	+	-21	-	15	=	-24
17	-	5	-	-21	+	15	=	48
17	-	5	-	-21	-	15	=	18
We call the sequence of integers divisible by K if + or - operators can be placed between integers in the
sequence in such way that resulting value is divisible by K. In the above example, the sequence is divisible by 7 (17+5+-21-15=-14) but is not divisible by 5.
You are to write a program that will determine divisibility of sequence of integers.
*/



int k;
int v[MAX];



// called with tryAll1(1, v[0])		// e.g. tryAll1(1, 17)
int tryAll1(int i, int sum) {
	if (i == n)
		return sum % k == 0;

	if (tryAll1(i + 1, sum + v[i]) || tryAll1(i + 1, sum - v[i])	)
		return 1;

	return 0;

}





int fix(int a) {
	return (a % k + k) % k;//if mod is neg this is a fix
}

int tryAll2(int i, int mod) {
	int &ret = mem[i][mod];
	if (ret != -1)
		return ret;
	if (i == n)
		return ret = mod == 0;

	if (tryAll2(i + 1, fix(mod + v[i])) || tryAll2(i + 1, fix(mod - v[i])))
		return ret = 1;
	return ret = 0;

}



int main()
{
    return 0;
}
