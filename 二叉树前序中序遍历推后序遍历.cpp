#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//前序 A|BDE|C
//	  根|左 |右
//中序 DBE|A|C
//     左 |根|右
//故可以前序的第一个结点将中序分成左右子树再递归
string tree(string preorder, string inorder) {
	if (preorder.size() == 0) {
		return "";
	}
	if (preorder.size()==1){
		return preorder;
	}
	auto pos = inorder.find(preorder[0]);
	return tree(preorder.substr(1,pos),inorder.substr(0, pos))+  //左子树构成的后序遍历
		tree(preorder.substr(pos+1, inorder.size() - pos),inorder.substr(pos + 1, inorder.size() - pos))  //右子树构成的后序遍历
		+inorder[pos];  //根节点
}

int main(void) {
	string preorder, inorder;
	cin >> preorder >> inorder;
	cout << tree(preorder,inorder) << endl;
	return 0;
}