#pragma once

#define pt_min(a, b) (((a) < (b)) ? (a) : (b))
#define pt_max(a, b) (((a) < (b)) ? (b) : (a))
#define pt_min3(a, b, c) (pt_min(pt_min(a, b), c))
#define pt_max3(a, b, c) (pt_max(pt_max(a, b), c))
