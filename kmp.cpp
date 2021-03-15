#include<iostream>
#include<cstring>
using namespace std;
/*
	KMP的经典思想就是:
		当出现字符串不匹配时，
		可以记录一部分之前已经匹配的文本内容，
		利用这些信息避免从头再去做匹配。
	
	next前缀表：保存回溯的位置。为了避免循环，存数时-1，匹配时+1（当不匹配时，可以多次回溯）
	前缀：abcdef	不包括最后一个字符的子串——a/ab/abc/...
	后缀：不包括开始一个字符的子串——f/ef/def/...
	KMP经典题：leecode 28
	
*/

/*
	构造next数组：
	初始化
	处理前后缀不相同的情况
	处理前后缀相同的情况
*/

void getNext(int* next,const string& s){
	//指针i,j; 	i表示后缀末尾，j+1表示前缀末尾；
	//next[i] 表示 i（包括i）之前最长相等的前后缀长度（其实就是j）
	//1.初始化j = -1 ; i = 1(不包括开始一个字符);
	int j = -1;
	next[0] = j;
	for (int i = 1; i < s.size(); ++i)
	{
		//2.处理前后缀不相同的情况; 多次回溯
		while(j >= 0 && s[i] != s[j + 1]){
			j = next[j];
		}
		//3.处理前后缀相同的情况
		if(s[i] == s[j + 1]){	// 找到相同的前后缀
			j++;
		}
		next[i] = j;
	}
}


/*	匹配文本串和模式串	*/
int strStr(string s, string t){	
	//匹配空串，返回0；
	if(t.size() == 0)	return 0;
	int next[t.size()];
	getNext(next,s);
	int j = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		while(j >=0 && s[i] != t[j + 1]){
			j = next[j];
		} 
		if(s[i] == t[j + 1]){
			j++;
		}
		if(j == t.size()-1){
			//匹配结束
			return i-t.size()+1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	string s, t;
	cin>>s>>t;
	cout<<strStr(s,t)<<endl;
	return 0;
}
