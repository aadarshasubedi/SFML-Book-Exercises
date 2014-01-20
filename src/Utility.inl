template <typename T>
std::string toString(const T& value) {
    std::stringstream stream;
    stream << value;
    return stream.str();
}

template< typename T >inline
const std::type_info& getType( T& object ) {
    return typeid(object);
}

template< typename T >inline
const std::type_info& getType(const T& object ) {
    return typeid(object);
}
