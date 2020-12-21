	cout<<"insert fix";
	
	}	

	void leftRotate(NodePtr x)
	{
		NodePtr y = x->right;
		x->right = y->left;

		if (y->left != TNULL)
		{
			y->left->parent = x;
		}
		
		y->parent = x->parent;

		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
		
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
