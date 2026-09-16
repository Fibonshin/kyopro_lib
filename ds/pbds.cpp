#include "../header.cpp"

// https://hogloid.hatenablog.com/entry/2014/09/23/132440
// https://atcoder.jp/contests/arc033/submissions/79284307
// https://atcoder.jp/contests/abc475/submissions/79284178
// set + k番目取得。(kは0-indexed)
// lessで昇順、greaterで降順
// muitisetにしたいなら、pair<data,id>みたいにする必要がある
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename KEY>
using pbds_set = tree<KEY, null_type, less<KEY>, rb_tree_tag,
                      tree_order_statistics_node_update>;
