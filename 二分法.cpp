#include<iostream>
#include<vector>
#include<algorithm
using namespace std;

int binarySearch(vector<int>& v,int target){
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while(left <= right){   //target 定义在左闭右闭[left , right]
		mid = (left + right)/2;  //防止溢出，也可写为mid = left + (right - left)/2;
		if(target < v[mid]){
			right = mid - 1;	
		}else if(target > v[mid]){
			left = mid + 1;
		}else{
			return mid;	
		}
	}
	//跳出while的条件是left > right,即区间为[right, left]/[0,-1]/[0,num.size()+1]

	//如果要找到合适的插入位置：return right+1;/left
		//所有元素之前[0,-1] return right + 1;/left
		//插入数组位置 return right + 1;/left
		//所有元素之前[0,v.size()] return right + 1;/left

	//如只需要判断数组中是否存在 return -1；
	return -1;
}

int binarySearch2(vector<int>& v,int target){
	int left = 0;
	int right = v.size();
	int mid;
	while(left < right){   //target 定义在左闭右开[left , right）	
		mid = (left + right)/2;
		if(target < v[mid]){
			right = mid;	//右边不能取到
		}else if(target > v[mid]){
			left = mid + 1;
		}else{
			return mid;	
		}
	}
	//跳出while的条件是left >= right,即区间为[right, left]/[0,-1]/[0,num.size()+1]

	//如果要找到合适的插入位置：return right;/left
		//所有元素之前[0,0） return right;/left
		//插入数组位置 return right;/left
		//所有元素之前[0,v.size()） return right;/left

	//如只需要判断数组中是否存在 return -1；
	return -1;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);
	
	for (int i = 0; i < 10; ++i)
	{
		cout<<v[i]<<' ';
	}
	cout<<endl;
	cout<<binarySearch(v,0)<<endl;
	cout<<binarySearch2(v,0)<<endl;
	return 0;
}

