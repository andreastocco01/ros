# Ros

roscore -> fa partire un ros master

rosrun <nome_package> <nome_eseguibile> ->  crea un nodo contenente l'eseguibile

per creare un workspace catkin:
- posizionarsi dentro alla cartella desiderata
- creare una sottocartella src
- catkin_make
- source ~/gits/ros/devel/setup.bash per poter eseguire il codide ros (messo dentro a .bashrc)

per creare un package:
- posizionarsi dentro la cartella src del workspace
- catkin_create_pkg <nome_package> <dependencies> -> crea un package ros

catkin_make per compilare i sorgenti

### Publisher

`publish(message)` non pubblica effettivamente il messaggio, ma lo "parcheggia" nella coda di attesa (la cui dimensione viene specificata quando viene istanziato il publisher).

un thread separato si occupa di inviare effettivamente il messaggio al topic. se il numero di messaggi in coda supera la dimensione di essa, i messaggi piu' vecchi vengono cancellati per far spazio a quelli piu' recenti.

### Subscriber

quando arriva un nuovo messaggio, esso viene salvato in una coda di attesa (stesso funzionamento di quella del publisher) finche' Ros non da' la possibilita' al subscriber di eseguire la funzione di callback.

Ros eseguira' una callback solo quando gli daremo il permesso di farlo. ci sono due modi per fare questo:
- `ros::spinOnce()` -> chiede a Ros di eseguire tutte le callback in sospeso di ogni subscriber e poi ci restituisce il controllo
- `ros::spin()` -> chiede a Ros di attendere e di eseguire le callback fino a quando il nodo non viene spento. e' equivalente a:

```c++
while (ros::ok()) {
    ros::spinOnce();
}
```

se il nodo non deve solamente eseguire le callback, allora un loop con `ros::spinOnce()` e' la scelta corretta (ovviamente).