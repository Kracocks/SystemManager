create table if not exists IDENTIFIANT(
    id_ident integer primary key autoincrement,
    email text(50),
    password text(100)
);

create table if not exists SERVICE(
    id_service integer primary key autoincrement,
    nom text(30)
);

create table if not exists UTILISE(
    id_ident int,
    id_service int,
    foreign key (id_ident) references IDENTIFIANT(id_ident),
    foreign key (id_service) references SERVICE(id_service),
    unique (id_ident, id_service)
);

create table if not exists TOKEN_GROUP(
    id_token_group integer primary key autoincrement,
    id_service int,
    nom_groupe text(50),
    foreign key (id_service) references SERVICE(id_service)
);

create table if not exists TOKEN(
    id_token integer primary key autoincrement,
    id_token_group int,
    valeur_token text(100),
    foreign key (id_token_group) references TOKEN_GROUP(id_token_group)
);