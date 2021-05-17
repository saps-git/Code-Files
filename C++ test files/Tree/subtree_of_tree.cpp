/* run in leetcode #572, as input trees not here */
//s (big tree),  t (small tree)

bool isSame(node* s, node* t){ 
    if(!s || !t) //if either of them become null 
        return s == t; //then they both need to be null in order to be true

    else if(s->data == t->data) //if the node matches
        return isSame(s-left, t->left) && isSame(s->right, t->right); //check same for left and right subtree in both tress

    return false;
}

bool isSubtree(node* s, node* t){
    if(!s) 
        return false;

    else if(isSame(s, t)) // check is both trees are the same 
        return true; 
        
    return isSubtree(s->left, t) || isSubtree(s->right, t); //recursive call to find the node of s which matches t root
}