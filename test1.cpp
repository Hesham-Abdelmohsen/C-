	void insertFix(NodePtr k) 
	{
		NodePtr u ;
		
		while(k->parent->color == 1)
		{
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left;
				
				// u ==>red
				if(u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
		            k->parent->parent->color = 1;
         		    k = k->parent->parent;					
				}
				
				//u ==>black
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
			        k->parent->parent->color = 1;
			        leftRotate(k->parent->parent);
				}
			}
			
			else
			{
				u = k->parent->parent->right;
				
				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
			        k->parent->parent->color = 1;
			        rightRotate(k->parent->parent);
				}
				
			}
			
			if(k==root)
			{
				break;
			}	
		}
		root->color = 0; 		
	///////////////
	cout<<"insert fix";
	
	}	

	void insert(int key) 
	{
		cout<<"hhhhhhhhhhhhhhhhh\n";
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
//////////////////////////////////////
		cout<<node->data;
////////////////////////////////////
		node->left = TNULL;
		node->right = TNULL; 
		node->color = 1;    // red by default
		
		NodePtr y = nullptr;
		NodePtr x = this->root;
		////////////////
		cout<<"\nx\n"<<x->data<<"\n";
		///////////////
		cout<<"\nx\n"<<TNULL<<"\n";
		///////////////////////
		while (x != TNULL) 
		{
			cout<<"\n\nWhile\n";
			y = x;
			
			if (node->data < x->data) 
			{
				x = x->left;				
			}
			
			else
			{
				x = x->right;
			}
		}	
		
		//	x ==> became null
		
		node->parent = y;
		
		if (y == nullptr)
		{
			root = node;
		}		
		else if (node->data < y->data)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}
		
		if (node->parent == nullptr)
		{
			node->color = 0; // black
		}		
		if (node->parent->parent == nullptr)
		{
			return; // remain by default
		}
		/////////////////
		cout<<"insert ";
		insertFix(node);
		cout<<"insert ";
	}
