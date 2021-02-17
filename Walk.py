from visual import ∗
import random
random.seed ( None )
jmax = 1000
xx =yy = z z = 0 . 0
# Seed g e n e r ator , None => systemclock
# Start at origin
graph 1 = display( x =0 , y =0 , w i dth = 600 , height = 600, title = ’3D Random Walk’ ,
forward =( −0.6 , −0.5 , −1) )
# Curve , i t s p a r a m e t e r s and l a b e l s
pts
= c u r v e ( x= l i s t ( r a n g e ( 0 , 1 0 0 ) ) , r a d i u s = 1 0 . 0 , c o l o r = c o l o r . y e l l o w )
xax
= c u r v e ( x= l i s t ( r a n g e ( 0 , 1 5 0 0 ) ) , c o l o r = c o l o r . r e d , p o s = [ ( 0 , 0 , 0 ) , ( 1 5 0 0 , 0 , 0 ) ] , r a d i u s = 1 0 . )
yax
= c u r v e ( x= l i s t ( r a n g e ( 0 , 1 5 0 0 ) ) , c o l o r = c o l o r . r e d , p o s = [ ( 0 , 0 , 0 ) , ( 0 , 1 5 0 0 , 0 ) ] , r a d i u s = 1 0 . )
zax
= c u r v e ( x= l i s t ( r a n g e ( 0 , 1 5 0 0 ) ) , c o l o r = c o l o r . r e d , p o s = [ ( 0 , 0 , 0 ) , ( 0 , 0 , 1 5 0 0 ) ] , r a d i u s = 1 0 . )
xname = l a b e l ( t e x t = "X" , p o s = ( 1 0 0 0 , 1 5 0 , 0 ) , box = 0 )
yname = l a b e l ( t e x t = "Y" , p o s = ( − 1 0 0 , 1 0 0 0 , 0 ) , box = 0 )
zname = l a b e l ( t e x t = "Z" , p o s = ( 1 0 0 , 0 , 1 0 0 0 ) , box = 0 )
✝
p t s . x [ 0 ] = p t s . y [ 0 ] = p t s . z [ 0 ] =0
f o r i in range (1 , 100) :
xx += ( random . random ( ) − 0 . 5 ) ∗ 2 .
yy += ( random . random ( ) − 0 . 5 ) ∗ 2 .
z z += ( random . random ( ) − 0 . 5 ) ∗ 2 .
pts.x[ i ] = 200∗ xx − 100
pts.y[ i ] = 200∗ yy − 100
pts.z[ i ] = 200∗ z z − 100
rat e (100)
p r i n t ( "This walk’s distance R =" , s q r t ( xx∗xx +
# Starting point
# −1 =< x =< 1
# −1 =< y =< 1
# −1 =< z =< 1
yy∗yy+ z z ∗ z z ) )