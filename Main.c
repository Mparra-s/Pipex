
char ***parse_arguments(int argc, char *argv[])
{
    char    ***arguments;
    char    **parameter;
    int     i;
    
    i = 0;
    arguments = malloc((argc -1) * sizeof(char));
    if (!arguments)
        return (0);
    parameter = ft_split(arguments, "");
    
}


int main(int argc, char *argv[])
{
    int i;
    char ***arguments;
    
    i = 0;
    arguments = parse_arguments(argc, argv);

}