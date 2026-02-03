if(index < candidates.size() && candidates[index] == candidates[index + 1])
      {
        find(candidates, target, index + 1, result, current, currSum);
        
        return;
      }