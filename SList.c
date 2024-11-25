#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

struct Node{
	uint32 NodeData;
	struct Node *NodeLink;
};

void Insert_Node_At_Begining(struct Node **List);
void Insert_Node_At_End(struct Node **List);
void Insert_Node_After(struct Node *List);
void Delete_Node_At_Begining(struct Node **List);
void Delete_Node(struct Node *List);
void Display_All_Nodes(struct Node *List);
uint32 Get_Length(struct Node *List);


struct Node *ListHead = NULL;

int main()
{
	uint8 UserChoice = 0;
    uint32 ListLength = 0;

    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Begining \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Begining \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                Insert_Node_At_Begining(&ListHead);
            break;
            case 2:
                Insert_Node_At_End(&ListHead);
            break;
            case 3:
                Insert_Node_After(ListHead);
            break;
            case 4:
                Delete_Node_At_Begining(&ListHead);
            break;
            case 5:
                Delete_Node(ListHead);
            break;
            case 6:
                Display_All_Nodes(ListHead);
            break;
            case 7:
                ListLength = Get_Length(ListHead);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
            case 8:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
	
	return 0;
}


void Insert_Node_At_Begining(struct Node **List){
	struct Node *TempNode = NULL;
	
	TempNode = (struct Node *)malloc(sizeof(struct Node));
	if(TempNode != NULL){
		printf("enter the Node Data :");
		scanf("%i", &TempNode->NodeData);
		
		if(NULL == *List){
			TempNode->NodeLink = NULL;
			*List = TempNode;
		}
		else{
			TempNode->NodeLink = *List;
			*List = TempNode;
		}
	}
	else{
		
	}
}

void Insert_Node_At_End(struct Node **List){
	struct Node *TempNode = NULL;
	struct Node *LastNode = NULL;
	
	TempNode = (struct Node *)malloc(sizeof(struct Node));
	if(TempNode != NULL){
		printf("enter the Node Data :");
		scanf("%i", &TempNode->NodeData);
		TempNode->NodeLink = NULL;
		
		
		if(NULL == *List){
			*List = TempNode;
		}
		else{
			LastNode = *List;
			while(LastNode->NodeLink != NULL){
				LastNode = LastNode->NodeLink;
			}
			LastNode->NodeLink = TempNode;
		}
	}
	else{
		
	}
}

void Insert_Node_After(struct Node *List){
	struct Node *TempNode = NULL;
    struct Node *NodeListCounter = NULL;
    uint32 NodePosition = 0;    /*  */
    uint32 ListLength = 0;      /*  */
    uint32 NodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &NodePosition);

    ListLength = Get_Length(List);
    if(NodePosition > ListLength){
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", ListLength);
    }
    else{
        NodeListCounter = List;
        while(NodeCounter < NodePosition){
            NodeCounter++;
            NodeListCounter = NodeListCounter->NodeLink;
        } /* TempNode points to the node where we have to insert after it */
        TempNode = (struct Node *)malloc(sizeof(struct Node));
        if(NULL != TempNode){
            printf("Enter Node Data : ");
            scanf("%i", &TempNode->NodeData);
            /* Connect the right side connection */
            TempNode->NodeLink = NodeListCounter->NodeLink;
            /* Connect the Left side connection */
            NodeListCounter->NodeLink = TempNode;
        }
        else{
            /* Nothing */
        }
    }
}

void Delete_Node_At_Begining(struct Node **List){
	struct Node *TempNode = *List;
    uint32 ListLength = 0;      /*  */

    ListLength = Get_Length(*List);
    if(ListLength == 0){
        printf("List is Empty , nothing to be deleted !! \n");
    }
    else{
        *List = TempNode->NodeLink;
        TempNode->NodeLink = NULL; /* TempNode is a free node */
        free(TempNode);
    }
}

void Delete_Node(struct Node *List){
	struct Node *NodeListCounter = List;
    struct Node *NextNode = List;
    uint32 NodePosition = 0;    /*  */
    uint32 ListLength = 0;      /*  */
    uint32 NodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &NodePosition);
    ListLength = Get_Length(List);
    if((NodePosition > ListLength) || (ListLength == 1)){
        printf("Please use Delete_Node_At_Beginning !! \n");
    }
    else{
        while(NodeCounter < (NodePosition - 1)){
            NodeCounter++;
            NodeListCounter = NodeListCounter->NodeLink;
        }
        NextNode = NodeListCounter->NodeLink;
        NodeListCounter->NodeLink = NextNode->NodeLink;
        free(NextNode);
    }
}

void Display_All_Nodes(struct Node *List){
	struct Node *TempNode = List;

    printf("Node Values : ");
    if(NULL == TempNode){
        printf("List is empty !! \n");
    }
    else{
        while(TempNode != NULL){
            printf("%i -> ", TempNode->NodeData);
            TempNode = TempNode->NodeLink;
        }
        if(NULL == TempNode){
            printf("NULL \n");
        }
    }
}

uint32 Get_Length(struct Node *List){
	struct Node *TempNode = List;
    uint32 NodeCount = 0;

    while(TempNode != NULL){
        NodeCount++;
        TempNode = TempNode->NodeLink;
    }

    return NodeCount;
}
