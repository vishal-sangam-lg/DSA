// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1
// Approach:
// Recursive -> process num. Create a node with num
// If you find ( for first time, call for left child
// If you find ( for next time, call for right child

// Iterative -> Process num and add to stack
// If you find )
// case 1: if stack.top left is null -> append to its left
// case 2: else append to its right

// Node* solve(string s, int &idx) {
//     if(idx >= s.length()) return NULL;

//     string currNum = "";
//     while(s[idx] >= '0' && s[idx] <= '9') {
//         currNum += s[idx++];
//     }

//     Node* currNode = new Node(stoi(currNum));

//     if(s[idx] == '(') {
//         idx++;
//         currNode -> left = solve(s, idx);
//     }
//     if(s[idx] == '(') {
//         idx++;
//         currNode -> right = solve(s, idx);
//     }

//     idx++;
//     return currNode;
// }

Node *treeFromString(string str)
{
    // Recursive Solution
    // int idx = 0;
    // return solve(str, idx);

    // Iterative Solution
    stack<Node *> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '(' && str[i] != ')')
        {
            string currNum = "";
            while (str[i] >= '0' && str[i] <= '9')
            {
                currNum += str[i++];
            }
            st.push(new Node(stoi(currNum)));
            i--;
        }
        else if (str[i] == ')')
        {
            Node *temp = st.top();
            st.pop();
            Node *root = st.top();
            if (root->left == NULL)
            {
                root->left = temp;
            }
            else
            {
                root->right = temp;
            }
        }
    }
    return st.top();
}