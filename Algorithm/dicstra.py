class Dicstra:

  def __init__(self):
    self.d = {}   # d[u]は頂点uの距離
    self.Q = []   # 頂点が距離順に格納されたヒープ．Q[0]が最小距離の頂点
    self.pos = {} # pos[u]は頂点uのヒープQの位置(添字)．Q[pos[u]]に頂点uが格納されている．
    self.pi = {}  # pi[u]は頂点uへの最短経路上で，頂点uの直前にある頂点

  def dijkstra(self, G, L, s):
    d = self.d 
    Q = self.Q
    self.initialize_single_source(G) # すべての頂点uについて距離d[u]を初期化する
    S = set() 

    for u in list(G.nodes): # Vに含まれるそれぞれの頂点uに対して
      self.insert(u) # Qに頂点uを加える

    d[s] = 0
    self.heapify_up(self.pos[s])
    # 最短距離を求める
    while len(Q) > 0: 
      u = self.extract_min()  
      S.add(u)      
      for v in list(G.adj[u]): 
        if not v in S: 
          self.relax(u, v, L) #     頂点vへの二つの経路のうち短いものを残しキューの並びも調整する
    return self.d

  def initialize_single_source(self, G):
    for v in list(G1.nodes):
      self.d[v] = math.inf
      self.pi[v] = -1

  def insert(self, u): # ヒープに頂点uを追加する
    # ヒープ条件を維持しないことに注意．
    # ヒープ条件を維持するにはinsertの後にheapify_up(Q, pos[u])を呼び出すこと．
    Q = self.Q
    pos = self.pos
    # 頂点uをヒープの末尾に追加．すでにuがヒープに存在する場合は追加しない
    if u not in pos:
      Q.append(u)
      pos[u] = len(Q) - 1

  def extract_min(self): # ヒープから最短距離の頂点を取り出す
    Q = self.Q
    pos = self.pos
    if len(Q) < 1: 
      raise Exception("heap under-flow")
    # ヒープの先頭にある頂点が最短距離の頂点
    min = Q[0]
    pos[min] = -1
    # ヒープの末尾にある頂点をヒープの先頭Q[0]に移動
    Q[0] = Q[len(Q) - 1]
    pos[Q[0]] = 0
    del Q[len(Q) - 1]
    # ヒープ条件を満たすようにQ[0]を移動する
    if len(Q) > 1:
      self.heapify_down(0)
    # 最短距離の頂点を返す
    return min

  def relax(self, u, v, L): # ある頂点同士を結ぶ経路について、他に最適な経路があるか探索
    if (u, v) in L:
      luv = L[(u, v)]
    else:
      luv = L[(v, u)]
    if self.d[v] > self.d[u] + luv:
      self.d[v] = self.d[u] + luv
      self.pi[u] = u
      self.heapify_up(self.pos[v])

  def heapify_up(self, i): # ヒープ条件を満たすように，ヒープのi番目の頂点を上に移動する
    d = self.d
    Q = self.Q
    pos = self.pos
    # ヒープのi番目の頂点をssとし，ssの距離をsdとする
    ss = Q[i]
    sd = d[ss]

    # 頂点ssをssの祖先と比べて，ヒープ条件を満たす位置を探す
    pi = (i - 1) // 2 # 親の添字．Q[i]の親がQ[pi]
    while pi > -1: # 親が存在する間，
      # 頂点ssの祖先の頂点をpとし，pの距離をpdとする
      p = Q[pi]
      pd = d[p]
      # 祖先pの距離が頂点ssの距離より長くなければヒープ条件を満たすのでwhileループを終了する
      if pd <= sd:
        break
      # 親pの距離が頂点ssの距離より長いので，親pを子の位置Q[i]に移動する
      if log:
        print('heapify_up 頂点ss', ss, '祖先', p, 'ssの距離', sd, '祖先の距離', pd)
      Q[i] = p
      pos[p] = i
      # 親のさらに親についてwhileの次の繰り返しでヒープ条件を満たすように処理する
      i = pi
      pi = (i - 1) // 2

    # ヒープのi番目の位置に頂点ssを格納する．iはwhileループで変わる場合があるので注意すること．
    Q[i] = ss
    pos[ss] = i

  def heapify_down(self, i): # ヒープ条件を満たすように，ヒープのi番目の頂点を下に移動する
    d = self.d
    Q = self.Q
    pos = self.pos
    # ヒープに格納されている頂点数がQlen
    Qlen = len(Q)
    # ヒープのi番目の頂点をppとし，ppの距離をpdとする
    pp = Q[i]
    pd = d[pp]

    # 頂点ppとppの子孫を比べて，ヒープ条件を満たす位置に頂点pを移動する．
    li = 2 * i + 1 # ヒープのi番目の左の子の添字
    while li < Qlen:
      # 頂点ppの左右の子のうち距離が短い方の頂点をsとし，sのヒープ上の位置をsi，sの距離をsdとする．
      # ひとまず左の子をsとする．
      si = li
      s = Q[si]
      sd = d[s]
      # 頂点ppに右の子が存在し，左の子より距離が短いならば，右の子をsとする．
      ri = li + 1 # 右の子の添字
      if ri < Qlen: # 右の子が存在する
        r = Q[ri]
        rd = d[r]
        if rd < sd: # 左の子より右の子の方が距離が短い．
          si = ri
          s = r
          sd = rd
      # 親pの距離が子sの距離より長くなければヒープ条件を満たすのでwhileループを終了する
      if pd <= sd:
        break
      # 親pの距離が子sの距離より長いので，親pを子の位置Q[i]に移動する
      if log:
        print('heapify_down 頂点pp', pp, '子孫', s, 'ppの距離', pd, '子孫の距離', sd)
      Q[i] = s
      pos[s] = i
      # 子のさらに子についてwhileの次の繰り返しでヒープ条件を満たすように処理する
      i = si
      li = 2 * i + 1 # ヒープのi番目の左の子の添字

    # 親のところに先頭の頂点を移動する
    Q[i] = pp
    pos[pp] = i

  def draw(self, filename = 'tmp'): # ヒープを図示する．ヒープの動作を確認するための関数
    d = self.d
    Q = self.Q
    A = pgv.AGraph(directed=True)
    for i in range(len(Q)):
      u = Q[i]
      if u in d:
        # print(i, Q[i], d[Q[i]])
        ud = d[u]
        A.add_node(i, label=f"<{u}<br/><font point-size=\"10pt\">d[{u}]={ud}</font>>")
      else:
        # print(i, Q[i])
        A.add_node(i, label=f"{u}")
      if i > 0:
        A.add_edge((i-1)//2, i)
    # ダミーの挿入
    if len(Q) % 2 == 0:
      A.add_node(len(Q), label='d', color='white', fontcolor='white')
      A.add_edge((len(Q)-1)//2, len(Q), color='white')
    A.layout('dot', args='-Nshape=box') # circle, oval, ellipse
    A.draw(F'{filename}.svg')
    display_svg(SVG(F'{filename}.svg'))
