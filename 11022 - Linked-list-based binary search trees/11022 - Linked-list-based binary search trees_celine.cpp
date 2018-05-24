void List_BST::insert(const int &num)
{
    ListNode* create = new ListNode(num);
    int level = 1;
    if(root==NULL)
    {
        root= create;
        Height = 1;
        return;
    }
    ListNode *p = root,*temp;
    while(1)
    {
        temp=p;
        while(num<p->key)
        {
            temp=p;
            p=p->left;
            level++;
            if(level>Height)Height=level;
            if(p==NULL)break;
        }
        if(p==NULL)
        {
            temp->left=create;
            return ;
        }
        else if(num<temp->key&&temp->left->right==NULL)
        {
            if(num==p->key)return ;
            temp->left->right=create;
            level++;
            if(level>Height)Height=level;
            return ;
        }
        else
        {
            if(num==p->key)return ;
            temp=p;
            p=p->right;
            level++;
            if(level>Height)Height=level;
            if(p==NULL)
            {
                temp->right = create;
                return ;
            }
        }
        while(num>p->key)
        {
            temp=p;
            p=p->right;
            level++;
            if(level>Height)Height=level;
            if(p==NULL)break;
        }
        if(p==NULL)
        {
            temp->right = create;
            return ;
        }
        else if(num>temp->key&&temp->right->left==NULL)
        {
            if(num==p->key)return ;
            temp->right->left = create;
            level++;
            if(level>Height)Height=level;
            return ;
        }
        else
        {
            if(num==p->key)return ;
            temp=p;
            p=p->left;
            level++;
            if(level>Height)Height=level;
            if(p==NULL)
            {
                temp->left = create;
                return ;
            }
        }
    }
}