class ThroneInheritance {
  public:
    queue<string> curOrder;
    string currentKing;
    unordered_map<string, queue<string>> parentChild;
    ThroneInheritance(string kingName) {
        currentKing = kingName;
        curOrder.push_back(kingName);
    }

    string successor(string x, queue<string> &curOrder) {
    }

    void birth(string parentName, string childName) {
        parentChild[parentName].push_back(childName);

        // 在现在王的基础上重新过一遍继承规则，将新生儿加进去
        // 其实也就是 curOrder 的头就是王
        successor(currentKing, curOrder);
    }

    void death(string name) {
        // 找到死去的那个名字，然后在 curOrder 中去掉
        curOrder.erase(curOrder.find(name));
    }

    vector<string> getInheritanceOrder() {
        return curOrder;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

// https://leetcode.com/contest/weekly-contest-208/problems/throne-inheritance/
