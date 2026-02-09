struct Node{
    string link;
    Node* prev;
    Node* next;
    Node(string link){
        this->link = link;
        prev = nullptr;
        next = nullptr;
    }
    Node(string link,Node* prev, Node* next){
        this->link = link;
        this->prev = prev;
        this->next = next;
    }
};

class BrowserHistory {
    Node* home;
    Node* curr;
    Node* latest;
public:
    BrowserHistory(string homepage) {
        home = new Node(homepage);
        curr = home;
        latest = home;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = curr->next;
        latest = curr;
    }
    
    string back(int steps) {
        while(curr!=home && steps>0){
            curr = curr->prev;
            steps--;
        }
        return curr->link;
    }
    
    string forward(int steps) {
        while(curr!=latest && steps>0){
            curr = curr->next;
            steps--;
        }
        return curr->link;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */