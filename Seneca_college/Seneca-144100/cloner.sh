repos=("IPC-Workshops" "IPC-Project" "BTP-Workshops" "BTP-Project" "IPC144NBB" "binder-cpp")
user="Seneca-144100"

for repo in ${repos[@]}; do
    git clone https://github.com/$user/$repo
    rm -rf $repo/.git $repo/.gitignore
done
