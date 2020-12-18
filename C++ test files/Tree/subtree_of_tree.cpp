/* run in leetcode #572, as input trees not here */
//s (big tree),  t (small tree)

bool isSame(node* s, node* t){ 
    if(!s || !t) //if either of them become null 
        return !s && !t;
    else if(s->data == t->data) //if the node matches
        isSame(s-left, t->left) && isSame(s->right, t->right); //check same for left and right subtree in both tress
    else
        return false
}

bool isSubtree(node* s, node* t){
    if(!s) 
        return false;
    else if(s->data == t->data) // if both node matches (t root, with current s node)
        return isSame(s, t); //call helper function to check all other nodes of t
    else
        return isSubtree(s->left, t) || isSubtree(s->right, t); //recursive call to find the node of s which matches t root
}