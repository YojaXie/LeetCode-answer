/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 
你可以将以下二叉树：

	1
   / \
  2   3
	 / \
	4   5

序列化为 "[1,2,3,null,null,4,5]"

提示:
这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 
不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<string>

using namespace std;


// Definition for a binary tree node.
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) 
	{
		string res;
		res.reserve(100000);
		if (!root) return res;
		queue<TreeNode*> buffer;
		buffer.push(root);
		while (!buffer.empty())
		{
			if (!buffer.front())
			{
				res += "NULL";
				buffer.pop();
				continue;
			}
			res = res + DECint2HEXstring(buffer.front()->val);
			buffer.push(buffer.front()->left);
			buffer.push(buffer.front()->right);
			buffer.pop();
		}
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) 
	{
		if (data.empty()) return NULL;
		TreeNode* res;
		queue<TreeNode*> buffer;
		vector<int> DECint = HEXstring2DECint(data);
		TreeNode* root = new TreeNode(DECint[0]);
		buffer.push(root);
		res = root;
		int offset = 1;
		int temp;
		while (!buffer.empty())
		{
			TreeNode* node = buffer.front();
			if (node)
			{
				// 节点的左子节点
				temp = DECint[offset];
				offset++;
				if (temp == 1280070990) node->left = NULL;
				else node->left= new TreeNode(temp);
				buffer.push(node->left);
				// 节点的右子节点
				temp = DECint[offset];
				offset++;
				if (temp == 1280070990) node->right = NULL;
				else node->right = new TreeNode(temp);
				buffer.push(node->right);
			}
			buffer.pop();
		}
		return res;
	}
	string DECint2HEXstring(int DECnum)
	{
		string HEXstring;
		char* p = reinterpret_cast<char*>(&DECnum);
		for (int i = 0; i < 4; i++)
			HEXstring.push_back(p[i]);
		return HEXstring;
	}
	vector<int> HEXstring2DECint(string HEXstring)
	{
		vector<int> DECint;
		DECint.reserve(25000);
		int* p = reinterpret_cast<int*>(&HEXstring[0]);
		uint16_t len= HEXstring.size() / 4;
		for (int i = 0; i < len; i++)
			DECint[i] = p[i];
		return DECint;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));