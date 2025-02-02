create table if not exists LOGIN(
    login_id integer primary key autoincrement,
    email text not null,
    password text not null
);

create table if not exists SERVICE(
    service_id integer primary key autoincrement,
    name text unique not null
);

create table if not exists USE(
    email text not null,
    service_id int not null,
    foreign key (email) references LOGIN(email) on delete cascade,
    foreign key (service_id) references SERVICE(service_id) on delete cascade,
    unique (email, service_id)
);

create table if not exists TOKEN_GROUP(
    token_group_id integer primary key autoincrement,
    login_id int not null ,
    group_name text not null,
    foreign key (login_id) references LOGIN(login_id) on delete cascade
);

create table if not exists TOKEN(
    token_id integer primary key autoincrement,
    token_group_id int not null,
    value text not null,
    foreign key (token_group_id) references TOKEN_GROUP(token_group_id) on delete cascade,
    unique (token_group_id, value)
);