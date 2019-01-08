include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct node{
     int data;
     struct node *left,*right;
};

/* Function to create a new node */

struct node* newnode(int element){
    struct node* temp=new node();
    temp->data=element;
    temp->left=temp->right=NULL;
    return temp;
}

/* Function to convert the Sorted array to BST */

struct node* construct(int arr[],int start,int end){

     if(start>end) return NULL;

     int mid=(start+end)/2;
     struct node *root=newnode(arr[mid]);
     root->right=construct(arr,mid+1,end);
     root->left=construct(arr,start,mid-1);

     return root;
}

/* Function for preorder traversal */

void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    if(root->left!=NULL){
         preorder(root->left);
    }
    if(root->right!=NULL){
        preorder(root->right);
    }
}
int main() {
 int t;
    cout<<"\nEnter the number of test cases: ";
    cin>>t;
    while(t--){
      int n;
         cout<<"\n\n\nEnter the number of elements: ";
      cin>>n;
         cout<<"\nEnter the elements of the array:\n";
      int arr[n];
      for(int i=0;i<n;i++){
          cin>>arr[i];
      }
      struct node *root=construct(arr,0,n-1);
         cout<<"\nThe preorder traversal of the tree is: \n";
      preorder(root);
      cout<<"\n";
 }
 return 0;
}
