repos=("OOP-Project" "BTP-Project" "OOP244-NAA-NBB-ZAA-Notes" "OOP-Workshops" "BTP-Workshops" "Fardad-s-Notes-Archive" "Downloadable-OOP244-BTP200-Notes")

for repo in ${repos[@]}; do
    git clone https://github.com/Seneca-244200/$repo
    rm -rf $repo/.git $repo/.gitignore
done
