#ifndef DYNAMIC_SUITOR_HPP_
#define DYNAMIC_SUITOR_HPP_

#include <networkit/auxiliary/Log.hpp>
#include <networkit/dynamics/GraphEvent.hpp>
#include <networkit/matching/SuitorMatcher.hpp>

namespace NetworKit {

class DynamicSuitorMatcher final : public SuitorMatcher {
public:
    DynamicSuitorMatcher(const Graph &G) : SuitorMatcher(G) {
        additionsPerNode.resize(G.upperNodeIdBound());
        affected.resize(G.upperNodeIdBound(), 0);
        wsPrev.resize(G.upperNodeIdBound());
        affectedNodes.reserve(G.numberOfNodes());
    }

    void insertBatch(const std::vector<GraphEvent> &additions);
    void doUpdate();

    std::vector<count> additionsPerNode;
    std::vector<unsigned char> affected;
    std::vector<edgeweight> wsPrev;
    std::vector<node> affectedNodes;
};
} // namespace NetworKit
#endif
