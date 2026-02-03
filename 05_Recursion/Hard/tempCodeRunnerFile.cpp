ector<string> result = solution.findPath(grid);

    cout << "Possible paths from top-left to bottom-right are: " << endl;
    for(const string& path : result)
    {
      cout << path << endl;
    }