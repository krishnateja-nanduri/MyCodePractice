struct InTreeNode {
  InTreeNode* next[26];
  bool isWord;
  
  InTreeNode(): isWord(false) {
    memset(next, 0, sizeof(TreeNode*) * 26);
  };
  
  void insert(const std::string& words, size_t start, size_t end) {
      InTreeNode* current = this;
      for (size_t i = start; i < end; ++i) {
          if (!current->next[words[i] - 'a']) {
              current->next[words[i] - 'a'] = new InTreeNode{};
          }
          current = current->next[words[i] - 'a'];
      }
      current->isWord = true;
  }
  
  bool query(const std::string& words, size_t start, size_t end) {
      InTreeNode* current = this;
      for (size_t i = start; i < end; ++i) {
          if (!current->next[words[i] - 'a']) {
              return false;
          }
          current = current->next[words[i] - 'a'];
      }
      return current->isWord;
  }
};


vector<int> Solution::solve(string goodWords, vector<string>& reviews) {
    const size_t NPOS = ~size_t(0);
    size_t wordStart = NPOS;
    InTreeNode InTree;
    for (size_t i = 0; i < goodWords.size(); ++i) {
        if (goodWords[i] == '_' && wordStart != NPOS) {
            InTree.insert(goodWords, wordStart, i);
            wordStart = NPOS;
        } else if (goodWords[i] != '_' && wordStart == NPOS) {
            wordStart = i;
        }
    }
    if (wordStart != NPOS) {
        InTree.insert(goodWords, wordStart, goodWords.size());
    }
    
    typedef std::pair<int /* idx */, int /* score */> HScore;
    std::vector<HScore> scores;
    scores.reserve(reviews.size());
    
    for (int i = 0; i < reviews.size(); ++i) {
        int score = 0;
        const auto& review = reviews[i];
        wordStart = NPOS;
        for (size_t i = 0; i < review.size(); ++i) {
            if (review[i] == '_' && wordStart != NPOS) {
                score += InTree.query(review, wordStart, i);
                wordStart = NPOS;
            } else if (review[i] != '_' && wordStart == NPOS) {
                wordStart = i;
            }
        }
        if (wordStart != NPOS) {
            score += InTree.query(review, wordStart, review.size());
        }
        // std::cout << "Review" << std::endl;
        // std::cout << i << std::endl;
        // std::cout << review << std::endl;
        // std::cout << score << std::endl;
        scores.emplace_back(i, score);
    }
    
    std::stable_sort(scores.begin(), scores.end(), [](const HScore& lhs, const HScore& rhs) {
       return lhs.second > rhs.second; 
    });
    
    std::vector<int> result;
    result.reserve(reviews.size());
    
    for (const auto& p: scores) {
        result.push_back(p.first);
    }
    
    return result;
}

