class BrowserHistory {
public:
// IMPLEMENTATION USING VECTOR
    vector<string> browser;
    int index, tabs;

    BrowserHistory(string homepage) {
        index=0,tabs=0;
        browser.push_back(homepage);
    }
    
    void visit(string url) {
        // if we have moves backward previously, means we have array available to add website
        // then increase the index and add the webpage
        if(index+1 < browser.size())
        {
            index++;
            browser[index]=url;
            tabs=index;
        }
        // we have to append new tab at the end
        else
        {
            tabs++;
            index++;
            browser.push_back(url);
        }
    }
    
    string back(int steps) {
        // move 'steps' backward, if we can't return the first tab (HOMEPAGE)
        steps>index ? index=0 : index-=steps;
        return browser[index];
    }
    
    string forward(int steps) {
        // move 'steps' forward, if we can't return the last tab
        index+steps > tabs ? index=tabs : index+=steps;
        return browser[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
























