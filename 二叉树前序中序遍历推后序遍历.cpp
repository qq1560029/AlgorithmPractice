#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//ǰ�� A|BDE|C
//	  ��|�� |��
//���� DBE|A|C
//     �� |��|��
//�ʿ���ǰ��ĵ�һ����㽫����ֳ����������ٵݹ�
string tree(string preorder, string inorder) {
	if (preorder.size() == 0) {
		return "";
	}
	if (preorder.size()==1){
		return preorder;
	}
	auto pos = inorder.find(preorder[0]);
	return tree(preorder.substr(1,pos),inorder.substr(0, pos))+  //���������ɵĺ������
		tree(preorder.substr(pos+1, inorder.size() - pos),inorder.substr(pos + 1, inorder.size() - pos))  //���������ɵĺ������
		+inorder[pos];  //���ڵ�
}

int main(void) {
	string preorder, inorder;
	cin >> preorder >> inorder;
	cout << tree(preorder,inorder) << endl;
	return 0;
}