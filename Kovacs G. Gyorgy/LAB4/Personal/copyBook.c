/*
    Lab 4
    Date: 2014.10.30
    Subject:
        Binary Search Trees
*/

//=======================================================================================

/*
    Inserting into a binary tree.
*/
void insert_into_binary_tree(int n){
    TreeNode *t;
    if (root != NULL){
        t = root;
        while (t != NULL){
            if (t->value < n){
                if (t->left == NULL){
                    t->left = (TreeNode*) malloc(sizeof(TreeNode));
                    t->left->value = n;
                }
                else{
                    t = t->left;
                }
            }
            else{
                if (t->value > n){
                    if (t->right){
                        t->right = (TreeNode*) malloc(sizeof(TreeNode));
                        t->right->value = n;
                    }
                    else{
                        t = t->right;
                    }
                }
            }
        }
    }
}

//=======================================================================================

/*
    Homework:
        5.4.4
    ALso:
        Test.
*/
