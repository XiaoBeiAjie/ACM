function<void(int)> dfs = [&] (int hs) {
        if (hs == n * m + 1) {
            
            int ok = 0;
            int cnt1 = 0, cnt2 = 0;
            for (int len = 1; len <= n; len ++ ) 
                for (int l = 1; l <= m; l ++ ) 
                    for (int r = 1; r + len - 1 <= n; r ++ ) 
                        for (int c = 1; c + l - 1 <= m; c ++ ) {
                            int t = g[r][c], f = 1;
                            for (int i = r; i <= r + len - 1 && f; i ++ ) 
                                for (int j = c; j <= c + l - 1 && f; j ++ ) 
                                    if (g[i][j] != t) f = 0;
                            if (f) cnt1 ++;
                            else cnt2 ++;
                        }
            if (cnt1 == cnt2) {
                for (int i = 1; i <= n; i ++ ) 
                    for (int j = 1; j <= m; j ++ ) 
                        cout << g[i][j] << " \n"[j == m];
                cout << "****\n";
            }
            
            return ;
        }
        int x = (hs + m - 1) / m; int y = hs - (x - 1) * m;
        for (int i = 0; i < 2; i ++ ) {
            g[x][y] = i;
            dfs(hs + 1);
        }   
    };
    dfs(1);