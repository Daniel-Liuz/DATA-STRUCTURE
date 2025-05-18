#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* createList(vector<int>&nums) {
    if(nums.empty())
        return nullptr;
    ListNode* head=new ListNode(nums[0]);
    ListNode* current =head;
    for (int i=1;i<nums.size();i++) {
        current->next=new ListNode(nums[i]);
        current=current->next;
    }
    return head;
}

ListNode* mergeTwoLists(ListNode *l1,ListNode *l2) {
    ListNode* dummy=new ListNode(0);
    ListNode* current=dummy;
    while(l1!=nullptr&&l2!=nullptr) {
        if(l1->val<l2->val) {
            current->next=l1;
            l1=l1->next;
        }
        else {
            current->next=l2;
            l2=l2->next;
        }
        current=current->next;
    }
    //连接剩余部分
    if(l1!=nullptr) {
        current->next=l1;
    }
    else {
        current->next=l2;
    }
    ListNode* result=dummy->next;
    delete dummy;
    return result;
}
void printList(ListNode *head) {
    if(head==nullptr) {
        cout<<"n"<<endl;
        return;
    }
    while(head!=nullptr) {
        cout<<head->val;
        if(head->next!=nullptr) {
            cout<<",";
        }
        head=head->next;
    }
    cout<<endl;
}
int main() {
    string input1,input2;
    getline(cin,input1);
    getline(cin,input2);
    vector<int>nums1,nums2;
    if(input1!="n") {
        stringstream ss1(input1);
        int num;
        while(ss1>>num) {
            nums1.push_back(num);
            if(ss1.peak()==',')
                ss1.ignore();
        }
    }
    if(input2!="n") {
        stringstream ss2(input2);
        int num;
        while(ss2>>num) {
            nums2.push_back(num);
            if(ss2.peak()==',')
                ss2.ignore();
        }
    }
    ListNode* l1=createList(nums1);
    ListNode* l2=createList(nums2);
    ListNode* mergeList=mergeTwoLists(l1,l2);
    printList(mergeList);
    return 0;
}