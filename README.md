# ✅ Cub3D
projet cursus 42 2019 - 2020

- Remarques :
parsing non optimisé du a une errur de conception : dans une optique d'amélioration de performance j'avais conçu le code pour sortir du programme avant la fin de gnl : problème : cela génère des leaks car la variable static allouée dans gnl ne peut être free sauf si on fini gnl !!! j'ai modifié le parsing pour éviter les leaks mais j'aurai du le refaire pour l'optimisation et la lisibilité du code !!!
Par ailleurs le makefile reste a modifier pour la version sous mac : source de la minilibix embarquée mais non modifié dans le build mac.
- Documentation :
  * [ray-casting] (https://fr.wikipedia.org/wiki/Raycasting) (https://lodev.org/cgtutor/raycasting.html) (http://projet-moteur-3d.e-monsite.com/pages/raycasting/raycasting.html) (http://forums.mediabox.fr/wiki/tutoriaux/flashplatform/affichage/3d/raycasting) (https://lodev.org/cgtutor/raycasting3.html)
  * [mlx_functions] (https://elearning.intra.42.fr/searches/search?query=minilibx) (https://harm-smits.github.io/42docs/) (https://github.com/keuhdall/images_example)
mlx_init : initialise la connexion entre le programme et le serveur graphique : envoie les ordres (e.g. ouvrir une fenetre, faire des dessins a l'interieur) et receptionne des évênements (est-ce que l'utilisateurs a cliqué sur une touche?);
mlx_loop : gere les évênements, donne la main a l'ensemble du systeme graphique mac. Cette fonction ne rend pas la main, il faut prevoir une touche lie a une fonction exit pour quitter.
mlx_key_hook ; permet d'appeler une fonction quand l'utlisateur appuie sur une touche.
mlx_pixel_put : cree un pixel. attention le pixel ne sont affichés qu'a l'appel de mlx_loop.
  * [Convertiseur couleur] (http://www.proftnj.com/RGB3.htm) (http://www.convertisseur-gratuit.com/webmaster/convertir-couleur.html)
sauvegarde d'une image bmp : http://fvirtman.free.fr/recueil/01_09_02_testbmp.c.php http://www.apprendre-en-ligne.net/info/images/formatbmp.pdf http://projet.eu.org/pedago/sin/ISN/7-format_BMP.pdf
  * commande valgrind
CUB=Cub3D;MAP=map.cub;valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --log-file=valgrind_log ./$CUB $MAP;grep -A1 "valgrind" valgrind_log|grep $CUB
valgrind --leak-check=yes ./cub3d map2.cub
