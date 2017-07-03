// 2d geometry {{{

typedef complex<double> P;

// 長さ
// double length = abs(a);

// 単位ベクトル
// P n = a/abs(a);

// 法線ベクトル
// P n1 = a*P(0, 1);
// P n2 = a*P(0, -1);

// 内積
double dot(P a, P b) {
    return a.real()*b.real() + a.imag()*b.imag();
}

// 外積
double cross(P a, P b) {
    return a.real()*b.imag() - a.imag()*b.real();
}

// 直交判定
// verified AOJ CGL_2_A
bool is_orthogonal(P a1, P a2, P b1, P b2) {
    return EQ(dot(a1-a2, b1-b2), 0.0);
}

// 平行判定
// verified AOJ CGL_2_A
bool is_parallel(P a1, P a2, P b1, P b2) {
    return EQ(cross(a1-a2, b1-b2), 0.0);
}

bool is_point_on_line(P a, P b, P c) {
    return abs(a-c) + abs(c-b) < abs(a-b) + EPS;
}

bool is_intersected_ls(P a1, P a2, P b1, P b2) {
    return cross(a2-a1, b1-a1)*cross(a2-a1, b2-a1) < EPS &&
           cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < EPS;
}

P intersection_l(P a1, P a2, P b1, P b2) {
    P a = a2 - a1;
    P b = b2 - b1;
    return a1 + a*cross(b, b1-a1)/cross(b, a);
}

// verified AOJ CGL_1_A
P projection_l_p(P p1, P p2, P p) {
    P a = p2 - p1;
    P b = p - p1;
    P c = a*dot(a, b)/(abs(a)*abs(a));
    return p1 + c;
}

// verified AOJ CGL_1_B
P reflection_l_p(P p1, P p2, P p) {
    return 2.0*projection_l_p(p1, p2, p) - p;
}

double dist_l_p(P a, P b, P c) {
    return abs(cross(b-a, c-a)) / abs(b-a);
}

double dist_ls_p(P a, P b, P c) {
    if(dot(b-a, c-a) < EPS) return abs(c-a);
    if(dot(a-b, c-b) < EPS) return abs(c-b);
    return dist_l_p(a, b, c);
}

double dist_ls_ls(P a1, P a2, P b1, P b2) {
    if(is_intersected_ls(a1, a2, b1, b2)){
        return 0;
    }
    return min({
            dist_ls_p(a1, a2, b1), 
            dist_ls_p(a1, a2, b2), 
            dist_ls_p(b1, b2, a2), 
            dist_ls_p(b1, b2, a2), 
            });
}

// }}}
