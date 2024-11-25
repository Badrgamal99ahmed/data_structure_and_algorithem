#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

#define DELETE_NODE_AT_BEGINNING

struct Node{
    uint32 NodeData;
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
};

struct Node *DLL = NULL;

void Insert_Node_At_Beginning(struct Node **List, uint32 Data);
void Insert_Node_At_End(struct Node *List, uint32 Data);
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position);
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List, uint32 position);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);

int main()
{
	Insert_Node_At_Beginning(&DLL, 11);
	Display_All_Nodes_Reverse(DLL);
	Insert_Node_At_Beginning(&DLL, 22);
	Display_All_Nodes_Reverse(DLL);
	Insert_Node_At_Beginning(&DLL, 33);
	Display_All_Nodes_Reverse(DLL);
	printf("----------------------\n");
	Insert_Node_At_End(DLL, 55);
	Display_All_Nodes_Reverse(DLL);
	Insert_Node_At_End(DLL, 66);
    Display_All_Nodes_Reverse(DLL);
	printf("----------------------\n");
	Insert_Node_After(DLL, 88, 2);
	Display_All_Nodes_Reverse(DLL);
	Insert_Node_After(DLL, 99, 3);
	Display_All_Nodes_Reverse(DLL);
	Insert_Node_After(DLL, 10, 5);
	Display_All_Nodes_Reverse(DLL);
	printf("----------------------\n");
	Insert_Node_Before(&DLL, 100, 3);
	Display_All_Nodes_Reverse(DLL);
	
	printf("************************\n");
	Delete_Node_At_Beginning(&DLL);
	Display_All_Nodes_Reverse(DLL);
	printf("************************\n");
	Delete_Node_At_End(DLL);
	Display_All_Nodes_Reverse(DLL);
	printf("*======================*\n");
	Delete_Node_At_Intermediate(DLL, 3);
	Display_All_Nodes_Reverse(DLL);
	Delete_Node_At_Intermediate(DLL, 5);
	Display_All_Nodes_Reverse(DLL);
	printf("*======================*\n");
	
	
	return 0;
}

void Insert_Node_At_Beginning(struct Node **List, uint32 Data){
	struct Node *TempNode = NULL;
	
	TempNode = (struct Node *)malloc(sizeof(struct Node));
	if(NULL != TempNode){
		TempNode->NodeData = Data;
		// check if it empty
		if((*List) == NULL){
			TempNode->LeftNodeLink = NULL;
			TempNode->RightNodeLink = NULL;
			(*List) = TempNode;
		}
		else{
			TempNode->RightNodeLink = (*List);
			TempNode->LeftNodeLink = NULL;
			(*List)->LeftNodeLink = TempNode;
			(*List) = TempNode;
		}
	}
	else{
		printf("Can not allocate new node !!\n");
	}
	
}

void Insert_Node_At_End(struct Node *List, uint32 Data){
    struct Node *TempNode = NULL;
    struct Node *NodeListCounterOne = NULL; 
    TempNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
        TempNode->RightNodeLink = NULL;
        NodeListCounterOne = List;
        while(NULL != NodeListCounterOne->RightNodeLink){
            NodeListCounterOne = NodeListCounterOne->RightNodeLink;
        }
        TempNode->LeftNodeLink = NodeListCounterOne;
        NodeListCounterOne->RightNodeLink = TempNode;
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_After(struct Node *List, uint32 Data, uint32 position){
	struct Node *TempNode = NULL;
    struct Node *NodeListCounterOne = NULL; 
    struct Node *NodeListCounterTwo = NULL; 
	
	NodeListCounterOne = List;
	while(position != 1){
		NodeListCounterOne = NodeListCounterOne->RightNodeLink;
		position--;
	}
	
	
    TempNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
		if(NULL == NodeListCounterOne->RightNodeLink){
			NodeListCounterOne->RightNodeLink = TempNode;
			TempNode->LeftNodeLink = NodeListCounterOne;
			TempNode->RightNodeLink = NULL;
		}
		else{
			NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
			
			NodeListCounterOne->RightNodeLink = TempNode;
			NodeListCounterTwo->LeftNodeLink = TempNode;
			TempNode->LeftNodeLink = NodeListCounterOne;
			TempNode->RightNodeLink = NodeListCounterTwo;
		}
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position){
	struct Node *TempNode = NULL;
    struct Node *NodeListCounterOne = NULL; 
    struct Node *NodeListCounterTwo = NULL; 
	uint32 NodePosition = position;
	
	NodeListCounterOne = (*List);
	while(NodePosition > (position - 1)){
		NodeListCounterOne = NodeListCounterOne->RightNodeLink;
		NodePosition--;
	}
	
	
    TempNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
		// Check if the position = 1 :: Adding the new node at the beginning.
		if(1 == position){
			TempNode->LeftNodeLink = NULL;
			TempNode->RightNodeLink = (*List);
			(*List)->LeftNodeLink = TempNode;
			(*List) = TempNode;
		}
		else{
			NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
			
			NodeListCounterOne->RightNodeLink = TempNode;
			NodeListCounterTwo->LeftNodeLink = TempNode;
			TempNode->LeftNodeLink = NodeListCounterOne;
			TempNode->RightNodeLink = NodeListCounterTwo;
		}
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Delete_Node_At_Beginning(struct Node **List){
	*List = (*List)->RightNodeLink;
	free((*List)->LeftNodeLink);
	(*List)->LeftNodeLink = NULL;
}

void Delete_Node_At_End(struct Node *List){
     struct Node *NodeListCounterOne = NULL;
    struct Node *NodeListCounterTwo = NULL;

    NodeListCounterOne = List;
    while(NodeListCounterOne->RightNodeLink != NULL){
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
    }
    NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
    NodeListCounterTwo->RightNodeLink = NULL;
    free(NodeListCounterOne);
    NodeListCounterOne = NULL;
}
void Delete_Node_At_Intermediate(struct Node *List, uint32 position){
	struct Node *NodeListCounterOne = NULL; 
    struct Node *NodeListCounterTwo = NULL; 
	uint32 NodePosition = position;
	if(1 == NodePosition){
        printf("Please use the Delete_Node_At_Beginning !! \n");
    }
    else{
		NodeListCounterOne = List;
		while(NodePosition > 1){
			NodeListCounterOne = NodeListCounterOne->RightNodeLink;
			NodePosition--;
		}
		NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
		NodeListCounterTwo->RightNodeLink = NodeListCounterOne->RightNodeLink;
		NodeListCounterOne->RightNodeLink->LeftNodeLink = NodeListCounterTwo;
		free(NodeListCounterOne);
		NodeListCounterOne = NULL;
	}
}

void Display_All_Nodes_Forward(struct Node *List){
    struct Node *TempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%d -> ", TempNode->NodeData);
    while(TempNode->RightNodeLink != NULL){
        TempNode = TempNode->RightNodeLink;
        printf("%d -> ", TempNode->NodeData);
    }
    if(NULL == TempNode->RightNodeLink){
        printf("NULL");
    }
    printf("\n");
}

void Display_All_Nodes_Reverse(struct Node *List){
    struct Node *TempNode = List;

    printf("\nTraversal in reverse direction ==> ");
    printf("Data : ");
    while(TempNode->RightNodeLink != NULL){
        TempNode = TempNode->RightNodeLink;
    }
    while(TempNode != NULL){
        printf("%d -> ", TempNode->NodeData);
        TempNode = TempNode->LeftNodeLink;
    }
    if(NULL == TempNode){
        printf("NULL");
    }
    printf("\n");
}
