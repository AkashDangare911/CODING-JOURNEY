class DLL{
    public:
    string tab;
    DLL *next;
    DLL *prev;
    
    DLL(string data){
        this->tab = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    DLL *browser;
    DLL *head;
    BrowserHistory(string homepage) {
        head = new DLL(homepage);
    }
    
    void visit(string url) {
        DLL *newTab = new DLL(url);
        newTab->prev=head;
        head->next = newTab;
        head=head->next;
    }
    
    string back(int steps) {
        while(steps-- && head->prev)
            head=head->prev;
        return head->tab;
    }
    
    string forward(int steps) {
        while(steps-- && head->next)
            head=head->next;
        return head->tab;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */