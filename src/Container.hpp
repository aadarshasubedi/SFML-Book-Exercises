#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <memory>

#include "Component.hpp"

namespace GUI {
    class Container : public Component {
        public:
            typedef std::shared_ptr<Container> Ptr;

        private:
            std::vector<Component::Ptr>	mChildren;
            int	mSelectedChild;

        public:
            Container();

            void pack(Component::Ptr component);

            virtual bool isSelectable() const;
            virtual void handleEvent(const sf::Event& event);

        private:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

            bool hasSelection() const;
            void select(std::size_t index);
            void selectNext();
            void selectPrevious();
    };
}

#endif // CONTAINER_HPP
