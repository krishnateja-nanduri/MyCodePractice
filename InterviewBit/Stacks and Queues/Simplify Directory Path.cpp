//https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string path) {

    if(path.empty()) return "/";
    int N = path.size(), begin = 0;
    vector<string> res;
    while(begin < N) {
        while(begin < N && path[begin] == '/') begin++;
        if(begin == N) break; // cannot forget this line!!!!
        int end = begin;
        while(end < N && path[end] != '/') end++;
        string sub = path.substr(begin, end - begin);
        if(sub == "..") {
            if(!res.empty()) res.pop_back();
        } 
        else if(sub == ".") {}
        else {
            res.push_back("/" + sub);
        }
        begin = end;
    }
    if(res.size() == 0) return "/";
    string final = "";
    for(string s : res) final += s;
    return final;
}
