template<typename T, typename U>
U my_accumulate(T _begin, T _end, U init){
    auto curr = _begin;

    while ( curr != _end )
        init += (*curr++);

    return init;
}